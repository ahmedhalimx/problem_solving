const SENIOR_AGE = 55;
const HANDICAP_THRESHOLD = 8

function openOrSenior(data) {
	let output = [];
	for (let pair of data) {
		if (pair[0] >= SENIOR_AGE && pair[1] >= HANDICAP_THRESHOLD) {
			output.push("Senior");
		} else {
			output.push("Open");
		}
	}
	return output;
}

function anotherWay(data) {
	return data.map(([age, handicap]) => {
		return (age >= SENIOR_AGE && handicap >= HANDICAP_THRESHOLD) ? "Senior" : "Open";
	});
	// return data.map((data) => (data[0] >= 54 && data[1] > 7) ? "Senior" : "Open");
}

console.log(anotherWay([[45, 12], [55, 21], [19, -2], [104, 20]]));
