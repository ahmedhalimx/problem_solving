function accum(s) {
	let output = [];
	for (let i = 0; i < s.length; ++i) {
		let char = s[i];
		output.push(char.toUpperCase());
		for (let j = 0; j < i; ++j) {
			output.push(char.toLowerCase())
		}
		if (i !== s.length - 1) output.push('-');
	}
	return output.join('');
}


let r = accum("abcd");
console.log(r);

function alt(s) {
	return s.split('').map((char, index) =>
		(char.toUpperCase() + char.toLowerCase().repeat(index))).join('-');
}

let ra = alt("abcd");
console.log(ra);
