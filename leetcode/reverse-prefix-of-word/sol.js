/**
 * @param {string} word
 * @param {character} ch
 * @return {string}
 */
var reversePrefix = function(word, ch) {
	let idx = word.indexOf(ch);
	let sub = word.substring(0, idx + 1).split("").reverse().join();
	sub.concat(word.substring(idx + 2, word.length));

	return sub;
};
