function persistence(num) {
	if (Math.floor(num / 10) === 0) return 0;

	let singleDigit = 1;
	for (let i = num; i !== 0; i = Math.floor(i / 10)) {
		singleDigit *= i % 10;
	}

	return (Math.floor(singleDigit / 10) === 0) ? 1 : 1 + persistence(singleDigit);
}

function alt(num) {
	if (Math.floor(num / 10) === 0) return 0;

	let singleDigit = 1;
	for (let i = num; i !== 0; i = Math.floor(i / 10)) {
		singleDigit *= i % 10;
	}

	return (Math.floor(singleDigit / 10) === 0) ? 1 : 1 + alt(singleDigit);
}

let a = 120102;

console.log(persistence(999));
