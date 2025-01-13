const API_BASE = "https://www.thecocktaildb.com/api/json/v1/1/";
const drinkList = document.getElementById("drink-list");
const cartItems = document.getElementById("cart-items");
const cartCount = document.getElementById("cart-count");

let cart = [];

async function fetchDrinks(search = "") {
  const url = search ? `${API_BASE}search.php?s=${search}` : `${API_BASE}random.php`;
  const response = await fetch(url);
  const data = await response.json();
  return data.drinks || [];
}

function displayDrinks(drinks) {
  drinkList.innerHTML = "";
  drinks.forEach((drink) => {
    const card = document.createElement("div");
    card.className = "card col-md-3 p-0";
    card.innerHTML = `
      <img src="${drink.strDrinkThumb}" class="card-img-top" alt="${drink.strDrink}">
      <div class="card-body">
        <h5 class="card-title">Name: ${drink.strDrink}</h5>
        <p class="card-text"><strong>Category:</strong> ${drink.strCategory}</p>
        <p class="card-text"><strong>Instructions:</strong> ${drink.strInstructions.slice(0, 20)}...</p>
        <button class="btn btn-success btn-sm add-to-cart" data-id="${drink.idDrink}" data-name="${drink.strDrink}" data-img="${drink.strDrinkThumb}">Add to Cart</button>
        <button class="btn btn-info btn-sm details" data-id="${drink.idDrink}">Details</button>
      </div>
    `;
    drinkList.appendChild(card);
  });

  setupEventListeners();
}

function addToCart(drink) {
  if (cart.length >= 7) {
    alert("Cannot add more than 7 items to the cart.");
    return;
  }

  cart.push(drink);
  updateCart();
}

function updateCart() {
  cartItems.innerHTML = "";
  cart.forEach((item, index) => {
    const row = document.createElement("tr");
    row.innerHTML = `
      <td>${index + 1}</td>
      <td><img src="${item.img}" width="50"></td>
      <td>${item.name}</td>
    `;
    cartItems.appendChild(row);
  });

  cartCount.textContent = cart.length;
}

function setupEventListeners() {
  document.querySelectorAll(".add-to-cart").forEach((button) => {
    button.addEventListener("click", (event) => {
      const drink = {
        id: button.dataset.id,
        name: button.dataset.name,
        img: button.dataset.img,
      };
      addToCart(drink);
    });
  });
}

fetchDrinks().then((drinks) => displayDrinks(drinks));

document.getElementById("search-button").addEventListener("click", () => {
  const searchInput = document.getElementById("search-input").value;
  fetchDrinks(searchInput).then((drinks) => displayDrinks(drinks));
});
