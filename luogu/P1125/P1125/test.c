#include<cstdio>
#include<cstring>
using namespace std;
char s[110];
const int prime[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };//´ò±í
int sum[26];
int main() {
	int maxn = 0, minn = 110;
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		sum[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (sum[i] > maxn) maxn = sum[i];
		if (sum[i] > 0 && sum[i] < minn) minn = sum[i];
	}
	for (int i = 0; i < 25; i++) {
		if (maxn - minn == prime[i]) {
			printf("Lucky Word\n%d", maxn - minn);
			return 0;//·µ»Ø
		}
	}
	printf("No Answer\n0");
	return 0;
}