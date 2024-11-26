#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isSubsequence(char* s, char* t)
{
	if (!s || *s == '\0') return true;
	int slen = strlen(s), tlen = strlen(t);
	int sf = 0, sl = slen - 1;
	int tf = 0, tl = tlen - 1;

	/* char sbsqnc[slen]; // doesn't work for some reason */
	char *sbsqnc = calloc(slen + 1, sizeof(char));

	while (tf <= tl && sf <= sl) {
		if (t[tl] == s[sl])
			sbsqnc[sl--] = t[tl--];
		else if (t[tf] == s[sf])
			sbsqnc[sf++] = t[tf++];
		else
			++tf, --tl;
	}
	bool result = (strcmp(s, sbsqnc) == 0);
	free(sbsqnc);
	return result;
}

int main(void)
{
	char *t = "basdacdslkadbsl", *s = "bcd";
	printf("%s %s a subsequence of %s\n", s, (isSubsequence(s, t))? "is" : "is not", t);
	return 0;
}
