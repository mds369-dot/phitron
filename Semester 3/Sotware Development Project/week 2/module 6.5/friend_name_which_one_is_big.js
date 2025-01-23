const checkFriends = (array) => {
    if (array.length === 0) {
        return "";
    }

    let biggestName = "";

    for (let i = 0; i < array.length; i++) {
        const element = array[i];

        if (element.length > biggestName.length) {
            biggestName = element;
        }
    }
    return biggestName;
}

var friends = ["rahim", "karim", "abdul", "sadsd", "heroAlom"];
const bifriends = checkFriends(friends);

console.log(bifriends);