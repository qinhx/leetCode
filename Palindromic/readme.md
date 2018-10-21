

Given a string **s**, find the longest palindromic substring in **s**. You may assume that the maximum length of **s** is 1000.

大神的简单代码必须看下，必须服

https://blog.csdn.net/u013949069/article/details/72054084

```C++
 
// 暴力方案
inline bool isPalindrome(const string &s, int n1, int n2) {
	for (--n2; n1 < n2; ++n1, --n2) if (s[n1] != s[n2]) return false;
	return true;
}
string findLongestPalindromeBrute(string s) {
	int sl(s.length()), mlen(1), start(0);
	for (int k1(0); k1 < sl; ++k1) {
		for (int k2(k1 + mlen + 1); k2 <= sl; ++k2) {
			if (isPalindrome(s, k1, k2)) start = k1, mlen = k2 - k1;
		}
	}
	return s.substr(start, mlen);
}
 
// 动态规划
string findLongestPalindromeDP(string s) {
	int sl(s.length()), mlen(1), start(0);
	vector<vector<bool>> dpm(sl, vector<bool>(sl, false));
	for (int k1(0); k1 < sl; ++k1) dpm[k1][k1] = true;
	for (int k1(0); k1 < sl - 1; ++k1) {
		if (s[k1] == s[k1 + 1]) {
			dpm[k1][k1 + 1] = true;
			if (!start) start = k1, mlen = 2;
		}
	}
	for (int kn(3); kn <= sl; ++kn) {
		for (int k1(0); k1 <= sl - kn; ++k1) {
			if (dpm[k1 + 1][k1 + kn - 2] && s[k1] == s[k1 + kn - 1]) {
				dpm[k1][k1 + kn - 1] = true;
				mlen = kn;
				start = k1;
			}
		}
	}
	return s.substr(start, mlen);
}
 
// 为中心扩展
string findLongestPalindromeCE(string s) {
	int sl(s.length()), mlen(1), start(0);
	for (int k1(1), kd(1); k1 < sl; ++k1) {
		for (kd = 1; k1 - kd >= 0 && k1 + kd < sl && s[k1 - kd] == s[k1 + kd];++kd);
		if (mlen < 2 * kd - 1) {
			mlen = 2 * kd - 1;
			start = k1 - kd + 1;
		}
	}
	for (int k1(1), kd; k1 < sl; ++k1) {
		for (kd = 0; k1 - kd >= 0 && k1 + kd + 1 < sl && s[k1 - kd] == s[k1 + kd + 1]; ++kd);
		if (mlen < 2 * kd) {
			mlen = 2 * kd;
			start = k1 - kd + 1;
		}
	}
	return s.substr(start, mlen);
}
 
// Manacher方案
string findLongestPalindromeManacher(string s) {
	string s1("$#");
	for (auto ch : s) s1 += ch, s1 += "#";  // Insert '#'  
	vector<int> pv(s1.size(), 0);
	int index(0), mlen(1);
	for (int k1(2), mid(1), mxr(0); k1 < s1.size(); ++k1) {
		pv[k1] = k1 < mxr ? min(pv[mid + mid - k1], mxr - k1) : 1;
		while (s1[k1 + pv[k1]] == s1[k1 - pv[k1]]) ++pv[k1];
		if (mxr < k1 + pv[k1]) {
			mxr = k1 + pv[k1];
			mid = k1;
		}
		if (mlen < pv[k1]) {
			mlen = pv[k1];
			index = k1;
		}
	}
	return s.substr((index - mlen) / 2, mlen - 1);
}
string findLongestPalindromeManacher2(string s) {
	string s1("#");
	for (auto ch : s) s1 += ch, s1 += "#";  // Insert '#'  
	int sl1(s1.length()), index(0), mlen(1);
	vector<int> pv(sl1, 0);
	for (int k1(1), kd(1), kt; k1 < sl1;) {
		while (0 <= k1 - kd && k1 + kd < sl1 && s1[k1 - kd] == s1[k1 + kd]) ++kd;
		pv[k1] = kd - 1;
		for (kt = 1; kt <= pv[k1] && pv[k1 - kt] < pv[k1] - kt; ++kt) pv[k1 + kt] = pv[k1 - kt];
		k1 += kt;
		kd = kd - kt;
	}
	for (int k1(1); k1 < sl1; ++k1) {
		if (mlen < pv[k1]) {
			mlen = pv[k1];
			index = k1;
		}
	}
	return s.substr((index - mlen) / 2, mlen);
}
 

```

动态规划

状态方程和转移方程式最重要的