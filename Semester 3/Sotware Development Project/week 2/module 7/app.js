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
    p.classList.add("child");
    p.innerText = inputValue;

    container.appendChild(p);

    document.getElementById("search-box").value = "";
    const allComments = document.getElementsByClassName("child");

    // for (let i = 0; i < allComments.length; i++) {
    //     const element = array[i];
        
    // }
    console.log(allComments);
    for(const element of allComments)
    {
        element.addEventListener("click", (e) => 
        {
            e.target.parentNode.removeChild(element);
        });
    }

});

// const handleSearch = (event) => {
//     console.log("Hi, BOXXX");
// }

fetch("https://jsonplaceholder.typicode.com/users")
    .then(res => res.json())
    .then(data => {
        console.log(data);
    })
    .catch((err) => {
        console.log(err);
    });



const displayData = (userData) => {
    const container = document.getElementsById("userData-container");
    

    userData.forEach(user => {
        const div = document.createElement("div");

        div.innerHTML = `
        <h4>title</h4>
        <p>Description</p>
        <button>Details</button>

        `
        container.appendChild(div);
    });
}
