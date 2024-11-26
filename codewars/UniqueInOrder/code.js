var uniqueInOrder = function(iterable) {
	let output = [];
	let prevElement = undefined;

	for (let element of iterable) {
		if (prevElement !== element) {
			output.push(element);
			prevElement = element;
		}
	}
	return output;
}

function alt(iterable) {
	return [...iterable].filter(function(e, i) { e !== iterable[i - 1] });
}


console.log([1, 2, 3, 4, 5][10]);
console.log(alt('AAAABBBCCDAABBB'));
