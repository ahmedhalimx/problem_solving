function digitalRoot(n) {
	let sum = 0;

	for (let i = n; i !== 0; i = Math.floor(i / 10)) {
		sum += i % 10;
	}

	return (sum.toString().length !== 1) ? digitalRoot(sum) : sum;
}

function alt(n) {
	return 1 + ((n - 1) % 9);
}

console.log(digitalRoot(122));
console.log(digitalRoot(96));
