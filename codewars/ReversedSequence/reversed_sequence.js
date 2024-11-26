const reverseSeq = n => {
	let x = [];
	for (let i = n; i > 0; --i) {
		x.push(i);
	}
	return x;
};

const alt = n => Array.from({ length: n }, () => n--)

console.log(alt(5));
