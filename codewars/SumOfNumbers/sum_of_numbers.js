function getSum(a, b) {
	let sum = 0;
	let start = 0;
	let end = 0;

	if (a > b) {
		start = b;
		end = a;
	} else {
		start = a;
		end = b;
	}

	for (let i = start; i <= end; ++i) {
		sum += a;
	}
	return sum;
}

//fokin hell!
let alt = (a, b) => (Math.abs(a - b) + 1) * (a + b) / 2;

console.log(alt(0, -1));
console.log(alt(0, 5));
