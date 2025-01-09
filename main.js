document.addEventListener('scroll', function() {
    // Query all the cards except the first one
    const cards = document.querySelectorAll('.latest_case-wrapper:not(:first-child)');

    cards.forEach(card => {
        const cardTop = card.getBoundingClientRect().top;
        const transitionStart = 700;
        const transitionEnd = 220;

        if (cardTop <= transitionStart && cardTop >= transitionEnd) {
            let percentage = (cardTop - transitionEnd) / (transitionStart - transitionEnd);
            // Calculate the scale of light mode to apply based on scroll position
            let brightness = 30 + 70 * (1 - percentage); // Interpolate brightness between 30% and 100%
            let grayscale = 100 * percentage; // Interpolate grayscale between 100% and 0%
            let scale = 1.01 - 0.01 * (1 - percentage); // Interpolate scale between 1.01 and 1
            card.style.filter = `brightness(${brightness}%) grayscale(${grayscale}%)`;
            card.style.transform = `scale(${scale})`;
        } else if (cardTop < transitionEnd) {
            // Fully light mode
            card.classList.add('light');
            card.classList.remove('dark');
            card.style.transform = 'scale(1)';
        } else {
            // Fully dark mode
            card.classList.add('dark');
            card.classList.remove('light');
            card.style.transform = 'scale(1.01)';
        }
    });
});