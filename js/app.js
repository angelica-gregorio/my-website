console.log("Website loaded successfully.");

function loadContent() {
    const pages = ['home', 'about', 'works', 'experience', 'education', 'references'];
    pages.forEach(page => {
        fetch(`${page}.html`)
            .then(response => response.text())
            .then(data => {
                const contentId = `${page}-content`;
                const element = document.getElementById(contentId);
                if (element) {
                    element.innerHTML = data;
                    element.id = page;
                    element.classList.add('content-box');
                }
            })
            .catch(error => console.error(`Error loading ${page}.html:`, error));
    });
}

function setupSmoothScroll() {
    document.querySelectorAll('a[href^="#"]').forEach(link => {
        link.addEventListener('click', function (e) {
            const href = this.getAttribute('href');
            if (href === '#') return;
            
            e.preventDefault();
            const target = document.querySelector(href);
            if (target) {
                const menuHeight = 60;
                const targetPosition = target.offsetTop - menuHeight;
                window.scrollTo({
                    top: targetPosition,
                    behavior: 'smooth'
                });
            }
        });
    });
}

window.addEventListener('load', function () {
    loadContent();
    setTimeout(setupSmoothScroll, 100);
});

// Function to handle the Live Clock and Greeting
function initializeExperience() {
    // --- 1. Calculate the Greeting ---
    let now = new Date();
    let hour = now.getHours();
    let greeting = "";

    if (hour >= 5 && hour < 12) greeting = "GOOD MORNING";
    else if (hour >= 12 && hour < 17) greeting = "GOOD AFTERNOON";
    else if (hour >= 17 && hour < 21) greeting = "GOOD EVENING";
    else greeting = "GOOD NIGHT";

    // --- 2. Update the HTML Header (No Alert) ---
    const headerElement = document.getElementById('connect-header');
    
    // We use innerHTML so we can keep the colored "class" span if you want, 
    // or you can just use plain text. Here is the format you asked for:
    if (headerElement) {
        headerElement.innerHTML = `<span class="keyword">class</span> HI! ${greeting}! LETS CONNECT`;
    }

    // --- 3. Live Digital Clock ---
    const clockElement = document.getElementById('clock-display'); // Make sure this ID matches your HTML
    if (clockElement) {
        setInterval(() => {
            const currentTime = new Date();
            clockElement.innerText = currentTime.toLocaleTimeString();
        }, 1000);
    }
}

// 2a: Retrieve input values and print to console
function handleFormSubmission() {
    const contactForm = document.getElementById('personalForm');
    
    if (contactForm) {
        contactForm.addEventListener('submit', function(event) {
            event.preventDefault(); 

            const nameValue = document.getElementById('userName').value;
            const emailValue = document.getElementById('userEmail').value;
            const messageValue = document.getElementById('userMsg').value;

            console.log("--- Form Submission Received ---");
            console.log("Name:", nameValue);
            console.log("Email:", emailValue);
            console.log("Message:", messageValue);
            console.log("--------------------------------");

            alert("Data captured! Check the browser console (F12).");
        });
    }
}

// Initialize everything on load
window.onload = () => {
    initializeExperience();
    handleFormSubmission();
};