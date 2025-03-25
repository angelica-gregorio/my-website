document.addEventListener("DOMContentLoaded", function () {
    document.getElementById("projectsBtn").addEventListener("click", function () {
        alert("Redirecting to projects section...");
        // Replace '#' with the actual URL or section ID
        window.location.href = "#projects";
    });

    document.getElementById("skillsBtn").addEventListener("click", function () {
        alert("Redirecting to skills section...");
        // Replace '#' with the actual URL or section ID
        window.location.href = "#skills";
    });
});
