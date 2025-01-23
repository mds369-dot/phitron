// const num = 5;
// num = 50;
// let name = "GIAS";

// name = "Shagor";
// name = "Ujjol";

// console.log(num)
// console.log(name)

// const countryName = "Bangladesh";

// const country = ` My country is ${countryName}`;

// console.log(country)

// const number = [1,2,3,4,5,6,7,8,9,10];

// const number2 = [11, 12, 13, 14, 15, 16, 17, 18, 19];

// console.log(...number, ...number2);

// const person = {
//     name: "test",
//     age: 10,
//     friends: ["karim", "rohim","jabbar"],
// };

// const {age, friends} = person;

// console.log(friends)

// const names = ["korim", 10, "lorem ifui slsdf dfu"];

// const [name, age, descrip] = names; 

// console.log(name, age, descrip)

// function sum(num1, num2){
//     const result = num1 + num2;
//     // console.log(result);
//     return result;
// }



// const output = sum(10, 20)
// console.log(output)
// const output2 = sum(10, 54)
// console.log(output)


// const products = [
//     {id:1, name: "xiaomi", description: "this is xiaomi", price: 500, color: "Black"},
//     {id:2, name: "iphone", description: "this is iphone", price: 800, color: "golden"},
//     {id:3, name: "xiaomi", description: "this is xiaomi", price: 500, color: "Black"},
//     {id:4, name: "iphone", description: "this is iphone", price: 500, color: "gray"},
//     {id:5, name: "xiaomi", description: "this is xiaomi", price: 600, color: "Black"},
// ]

// const result = products.forEach(pd=>{
//     console.log(products.id);
// });

// console.log(result);



// const sum=products.map(pd=>pd.id*2);

// console.log(sum)




// const result = products.filter(pd=>pd.color == "Black")

// console.log(result)




// for(let i = 0; i < products.length; i++)
// {
//     const element = products[i];
//     if(element.id == 3){
//         console.log(element);
//     }
// }


// const result = products.find(pd=>pd.id==3);

// console.log(result)




// const oddEven = (array) => {

//     let eventNumber = [];
//     let oddNumber = [];

//     for(let i = 0; i < array.lenght; i++)
//     {
//         const element = array[i];

//         if(element % 2 == 0)
//         {
//             eventNumber.push(element);
//         }
//         else
//         {
//             oddNumber.push(element);
//         }
//     }
//     return oddNumber;
// };

// const numbers = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28];

// const result = oddEven(numbers)
// console.log(result)

const checkFriends = (array) => {
    let biggestName = array[i];

    for (let i = 0; i < array.length; i++) {
        const element = array[i];

        if (element.length > biggestName.length) {
            biggestName = element;
        }
        
    }
    return biggestName;
}

const friends = ["Rohim", "Korim", "Jobbar", "Salam", "Borkot", "Preo","Bangladesh"]
const bifriends = checkFriends(friends)



console.log(bifriends)

alert()