function validBraces(braces) {
	const validPairs = ['()', '[]', '{}'];
	const openBraces = ['(', '[', '{'];

	let stack = [];

	for (let brace of braces) {
		if (!openBraces.includes(brace)) {
			if (!validPairs.includes(`${stack.pop()}${brace}`)) {
				return false;
			}
		} else {
			stack.push(brace);
		}
	}

	return (stack.length === 0);
}

function alt(braces) {
	let stack = [];

	const validPairs = {
		'(': ')',
		'[': ']',
		'{': '}'
	};

	for (let brace of braces) {
		if (validPairs[brace]) {
			stack.push(brace);
		} else {
			if (validPairs[stack.pop()] !== brace) {
				return false;
			}
		}
	}

	return stack.length;
}
