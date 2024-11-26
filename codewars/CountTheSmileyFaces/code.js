const validSmileys = [':D', ';D', ':-D', ';-D', ':~D', ';~D', ':)', ';)', ':-)', ';-)', ':~)', ';~)'];

function countSmileys(faces) {
	return faces.reduce((smileysRunningCount, currentFace) =>
		smileysRunningCount += (validSmileys.includes(currentFace) ? 1 : 0),
		0);
}

function alt(faces) {
	return faces.filter((face) => /^[:;][-~]?[)D]$/.test(face)).length;
}
