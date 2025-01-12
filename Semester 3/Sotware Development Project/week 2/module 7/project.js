const cartCount = document.getElementById("count")?.innerText || "0";
let convertedCount = parseInt(cartCount) || 0;


const loadAllProduct = () => {
    fetch('https://fakestoreapi.com/products')
        .then(res => res.json())
        .then((data) => {
            if (data && data.length > 0) {
                displayProduct(data);
            } else {
                document.getElementById("product-container").innerText = "No products available.";
            }
        })
        .catch(err => {
            console.error("Error fetching products:", err);
            document.getElementById("product-container").innerText = "Failed to load products.";
        });
};



const displayProduct = (products) => {
    const productContainer = document.getElementById("product-container");

    products.forEach((product) => {
        console.log(product);
        const div = document.createElement("div");
        div.classList.add("product");

        div.classList.add("card");
        div.innerHTML = `
             <img class="card-img" src="${product.image}" alt="${product.title}" />
            <h5>${product.title}</h5>
            <h3>Price: ${product.price}</h3>
            <p>${product.description.slice(0, 50)}</p>
            <button>Details</button>
            <button onclick="handleAddToCart('${product.title?.slice(0, 12)}',${product?.price})">Add to Cart</button>
        `;

        productContainer.appendChild(div);
    });
};

const handleAddToCart = (name, price) => {
    const container = document.getElementById("cart-main-container");
    
    const existingItem = [...container.children].find(
        child => child.querySelector("p")?.innerText === name
    );
    
    if (!existingItem) {
        const div = document.createElement("div");
        div.innerHTML = `
            <p>${name}</p>
            <h3 class="price">${price}</h3>
        `;
        container.appendChild(div);
        UpdateTotal();
    } else {
        alert("Item already in the cart");
    }
};

const UpdateTotal = () => {
    const allPrice = document.getElementsByClassName("price");
    let count = 0;
    for (const element of allPrice) {
        count += parseFloat(element.innerText) || 0;
    }
    document.getElementById("total").innerText = count.toFixed(2);
};



const singleProduct = (id) => {
    fetch(`https://fakestoreapi.com/products/${id}`)
        .then(res => res.json())
        .then(json => console.log(json))
        .catch(err => console.error("Error fetching single product:", err));
};

loadAllProduct();