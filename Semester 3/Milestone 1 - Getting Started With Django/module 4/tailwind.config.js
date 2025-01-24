/** @type {import('tailwindcss').Config} */
module.exports = {
   content: [
      "./templates/**/*.html", // Template files
      "./**/templates/**/*.html", // Template files in subdirectories   
      
   ],
   theme: {
     extend: {},
   },
   plugins: [],
 }