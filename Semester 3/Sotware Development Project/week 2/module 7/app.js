// const allBox = document.getElementsByClassName("box");

// console.log(allBox);

// for (let i = 0; i < allBox.length; i++) {
//     const element = allBox[i];
//     element.style.background = "green";
    
//     if(element.innerText == "box-5")
//     {
//         element.style.backgroundColor = "red";
//     }
// }

document.getElementById("handleADD").addEventListener("click", (event) => {
    const inputValue = document.getElementById("search-box").value;

    const container = document.getElementById("comment-container");

    const p = document.createElement("p");
    p.innerText = inputValue;

    container.appendChild(p);

    document.getElementById("search-box").value = "";

});

// const handleSearch = (event) => {
//     console.log("Hi, BOXXX");
// }