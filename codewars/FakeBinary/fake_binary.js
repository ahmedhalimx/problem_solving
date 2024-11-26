function fakeBin(x) {
	let digitArr = [];
	for (let char of x) {
		if (['4', '3', '2', '1', '0'].includes(char)) {
			digitArr.push('0');
		} else {
			digitArr.push('1');
		}
	}
	return digitArr.join('');
}

/*
 * function fakeBin(x) {
 *	return x.replace(/[0-4]/g, '0').replace(/[5-9]/g, '1');
 * }
 */
