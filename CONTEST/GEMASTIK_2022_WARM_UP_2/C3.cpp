#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// MIT License

// Copyright (c) 2020 William Chanrico

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/*
* Title: BigInt
* Description: Big Integer class (coded with competitive programming problems in mind)
* Date: 09-October-2017
* Author: William Chanrico
*/

#include <bits/stdc++.h>

class BigInt {
public:
    int sign;
    string s;

    BigInt()
        : s("")
    {
    }

    BigInt(string x)
    {
        *this = x;
    }

    BigInt(int x)
    {
        *this = to_string(x);
    }

    BigInt negative()
    {
        BigInt x = *this;

        x.sign *= -1;

        return x;
    }

    BigInt normalize(int newSign)
    {
        for (int a = s.size() - 1; a > 0 && s[a] == '0'; a--)
            s.erase(s.begin() + a);

        sign = (s.size() == 1 && s[0] == '0' ? 1 : newSign);

        return *this;
    }

    void operator=(string x)
    {
        int newSign = (x[0] == '-' ? -1 : 1);

        s = (newSign == -1 ? x.substr(1) : x);

        reverse(s.begin(), s.end());

        this->normalize(newSign);
    }

    bool operator==(const BigInt& x) const
    {
        return (s == x.s && sign == x.sign);
    }

    bool operator<(const BigInt& x) const
    {
        if (sign != x.sign)
            return sign < x.sign;

        if (s.size() != x.s.size())
            return (sign == 1 ? s.size() < x.s.size() : s.size() > x.s.size());

        for (int a = s.size() - 1; a >= 0; a--)
            if (s[a] != x.s[a])
                return (sign == 1 ? s[a] < x.s[a] : s[a] > x.s[a]);

        return false;
    }

    bool operator<=(const BigInt& x) const
    {
        return (*this < x || *this == x);
    }

    bool operator>(const BigInt& x) const
    {
        return (!(*this < x) && !(*this == x));
    }

    bool operator>=(const BigInt& x) const
    {
        return (*this > x || *this == x);
    }

    BigInt operator+(BigInt x)
    {
        BigInt curr = *this;

        if (curr.sign != x.sign)
            return curr - x.negative();

        BigInt res;

        for (int a = 0, carry = 0; a < s.size() || a < x.s.size() || carry; a++) {
            carry += (a < curr.s.size() ? curr.s[a] - '0' : 0) + (a < x.s.size() ? x.s[a] - '0' : 0);

            res.s += (carry % 10 + '0');

            carry /= 10;
        }

        return res.normalize(sign);
    }

    BigInt operator-(BigInt x)
    {
        BigInt curr = *this;

        if (curr.sign != x.sign)
            return curr + x.negative();

        int realSign = curr.sign;

        curr.sign = x.sign = 1;

        if (curr < x)
            return ((x - curr).negative()).normalize(-realSign);

        BigInt res;

        for (int a = 0, borrow = 0; a < s.size(); a++) {
            borrow = (curr.s[a] - borrow - (a < x.s.size() ? x.s[a] : '0'));

            res.s += (borrow >= 0 ? borrow + '0' : borrow + '0' + 10);

            borrow = (borrow >= 0 ? 0 : 1);
        }

        return res.normalize(realSign);
    }

    BigInt operator*(BigInt x)
    {
        BigInt res("0");

        for (int a = 0, b = s[a] - '0'; a < s.size(); a++, b = s[a] - '0') {
            while (b--)
                res = (res + x);

            x.s.insert(x.s.begin(), '0');
        }

        return res.normalize(sign * x.sign);
    }

    BigInt operator/(BigInt x)
    {
        if (x.s.size() == 1 && x.s[0] == '0')
            x.s[0] /= (x.s[0] - '0');

        BigInt temp("0"), res;

        for (int a = 0; a < s.size(); a++)
            res.s += "0";

        int newSign = sign * x.sign;

        x.sign = 1;

        for (int a = s.size() - 1; a >= 0; a--) {
            temp.s.insert(temp.s.begin(), '0');
            temp = temp + s.substr(a, 1);

            while (!(temp < x)) {
                temp = temp - x;
                res.s[a]++;
            }
        }

        return res.normalize(newSign);
    }

    BigInt operator%(BigInt x)
    {
        if (x.s.size() == 1 && x.s[0] == '0')
            x.s[0] /= (x.s[0] - '0');

        BigInt res("0");

        x.sign = 1;

        for (int a = s.size() - 1; a >= 0; a--) {
            res.s.insert(res.s.begin(), '0');

            res = res + s.substr(a, 1);

            while (!(res < x))
                res = res - x;
        }

        return res.normalize(sign);
    }

    // operator string(){
    // 	string ret = s;

    // 	reverse(ret.begin(), ret.end());

    // 	return (sign == -1 ? "-" : "") + s;
    // }

    string toString() const
    {
        string ret = s;

        reverse(ret.begin(), ret.end());

        return (sign == -1 ? "-" : "") + ret;
    }

    BigInt toBase10(int base)
    {
        BigInt exp(1), res("0"), BASE(base);

        for (int a = 0; a < s.size(); a++) {
            int curr = (s[a] < '0' || s[a] > '9' ? (toupper(s[a]) - 'A' + 10) : (s[a] - '0'));

            res = res + (exp * BigInt(curr));
            exp = exp * BASE;
        }

        return res.normalize(sign);
    }

    BigInt toBase10(int base, BigInt mod)
    {
        BigInt exp(1), res("0"), BASE(base);

        for (int a = 0; a < s.size(); a++) {
            int curr = (s[a] < '0' || s[a] > '9' ? (toupper(s[a]) - 'A' + 10) : (s[a] - '0'));

            res = (res + ((exp * BigInt(curr) % mod)) % mod);
            exp = ((exp * BASE) % mod);
        }

        return res.normalize(sign);
    }

    string convertToBase(int base)
    {
        BigInt ZERO(0), BASE(base), x = *this;
        string modes = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        if (x == ZERO)
            return "0";

        string res = "";

        while (x > ZERO) {
            BigInt mod = x % BASE;

            x = x - mod;

            if (x > ZERO)
                x = x / BASE;

            res = modes[stoi(mod.toString())] + res;
        }

        return res;
    }

    BigInt toBase(int base)
    {
        return BigInt(this->convertToBase(base));
    }

    friend ostream& operator<<(ostream& os, const BigInt& x)
    {
        os << x.toString();

        return os;
    }
};

bool intTest(int x, int y)
{
    BigInt A(x), B(y);

    // cout << x << " + " << y << " = " << A + B << "\n";
    assert((A + B).toString() == to_string(x + y));

    // cout << x << " - " << y << " = " << A - B << "\n";
    assert((A - B).toString() == to_string(x - y));

    // cout << x << " * " << y << " = " << A * B << "\n";
    assert((A * B).toString() == to_string(x * y));

    // cout << x << " / " << y << " = " << A / B << "\n";
    assert((A / B).toString() == to_string(x / y));

    // cout << x << " % " << y << " = " << A % B << "\n";
    assert((A % B).toString() == to_string(x % y));

    // cout << x << " == " << y << " = " << (A == B) << "\n";
    assert((A == B) == (x == y));

    // cout << x << " < " << y << " = " << (A < B) << "\n";
    assert((A < B) == (x < y));

    // cout << x << " > " << y << " = " << (A > B) << "\n";
    assert((A > B) == (x > y));

    // cout << x << " <= " << y << " = " << (A <= B) << "\n";
    assert((A <= B) == (x <= y));

    // cout << x << " >= " << y << " = " << (A >= B) << "\n";
    assert((A >= B) == (x >= y));
}

bool test()
{
    // cout << "616512316543123165465636565231654065565654065405640645 + 616512316543123165465416545405640645 = 616512316543123166082148881774777231031070610811281290\n";
    assert((BigInt("616512316543123165465636565231654065565654065405640645") + BigInt("616512316543123165465416545405640645")).toString() == "616512316543123166082148881774777231031070610811281290");

    // cout << "616512316543123165465416545405640645 - 616512316543123165465636565231654065565654065405640645 = -616512316543123164849124248688530900100237520000000000\n";
    assert((BigInt("616512316543123165465416545405640645") - BigInt("616512316543123165465636565231654065565654065405640645")).toString() == "-616512316543123164849124248688530900100237520000000000");

    // cout << "616512316543123165465636565231654065565654065405640645 * 616512316543123165465416545405640645 = 380087436449368097523788762423296535434518689762888646297835291324262922445487782876016025\n";
    assert((BigInt("616512316543123165465636565231654065565654065405640645") * BigInt("616512316543123165465416545405640645")).toString() == "380087436449368097523788762423296535434518689762888646297835291324262922445487782876016025");

    // cout << "616512316543123165465636565231654065565654065405640645 / 616512316543123165465416545405640645 = 1000000000000000000\n";
    assert((BigInt("616512316543123165465636565231654065565654065405640645") / BigInt("616512316543123165465416545405640645")).toString() == "1000000000000000000");

    // cout << "616512316543123165465636565231654065565654065405640645 % 616512316543123165465416545405640645 = 220019826013420565654065405640645\n";
    assert((BigInt("616512316543123165465636565231654065565654065405640645") % BigInt("616512316543123165465416545405640645")).toString() == "220019826013420565654065405640645");

    // cout << "616512316543123165465636565231654065565654065405640645 < 616512316543123165465416545405640645 = false\n";
    assert((BigInt("616512316543123165465636565231654065565654065405640645") < BigInt("616512316543123165465416545405640645")) == false);

    // cout << "616512316543123165465636565231654065565654065405640645 > 616512316543123165465416545405640645 = true\n";
    assert((BigInt("616512316543123165465636565231654065565654065405640645") > BigInt("616512316543123165465416545405640645")) == true);

    // cout << "616512316543123165465636565231654065565654065405640645 <= 616512316543123165465416545405640645 = false\n";
    assert((BigInt("616512316543123165465636565231654065565654065405640645") <= BigInt("616512316543123165465416545405640645")) == false);

    // cout << "616512316543123165465636565231654065565654065405640645 >= 616512316543123165465416545405640645 = true\n";
    assert((BigInt("616512316543123165465636565231654065565654065405640645") >= BigInt("616512316543123165465416545405640645")) == true);

    // cout << "HTJNH3RMEMSGCS6MM8M4AQKA006EQ0 base 30 to base 10 = 123456789123456778069461032848687693290175380\n";
    assert(BigInt("HTJNH3RMEMSGCS6MM8M4AQKA006EQ0").toBase10(30).toString() == "123456789123456778069461032848687693290175380");

    // cout << "A123B456C789 base " << 16 << " to base " << 10 << " = " << "177174721513353" << "\n";
    assert((BigInt("A123B456C789").toBase10(16)).toString() == "177174721513353");

    // cout << "194gh7f base " << 21 << " to base " << 10 << " = " << "123456789" << "\n";
    assert((BigInt("194gh7f").toBase10(21)).toString() == "123456789");

    // cout << "1010 base " << 2 << " to base " << 10 << " = " << "10" << "\n";
    assert((BigInt(1010).toBase10(2)).toString() == "10");

    // cout << "456 base " << 10 << " to base " << 8 << " = " << "710" << "\n";
    assert((BigInt(456).toBase(8)).toString() == "710");

    // cout << "123456789123156156219461032848 base " << 10 << " to base " << 19 << " = " << "91G5DCGA40DHF6D6715B29D" << "\n";
    assert((BigInt("123456789123156156219461032848").toBase(19)).toString() == "91G5DCGA40DHF6D6715B29D");

    // cout << "123456789 base " << 10 << " to base " << 16 << " = " << "75BCD15" << "\n";
    assert((BigInt(123456789).toBase(16)).toString() == "75BCD15");
}

BigInt gcd(BigInt A, BigInt B) {
    if (B == 0) return A;
    return gcd(B, A % B);
}

BigInt lcm(BigInt A, BigInt B) {
    if (A > B) swap(A, B);
    return A / gcd(A, B) * B;
}

BigInt n(BigInt k, BigInt max) {
    return max / k;
}



int main() {
    fast_io();
    //use ll when possible!
    string tempL, tempR; cin >> tempL >> tempR;
    BigInt L(tempL), R(tempR);

    string tA, tB, tC; cin >> tA >> tB >> tC;
    BigInt A(tA), B(tB), C(tC);
    BigInt nA1 = n(A, R);
    BigInt nB1 = n(B, R);
    BigInt nC1 = n(C, R);

    BigInt nAB1 = n(lcm(A, B), R);
    BigInt nAC1 = n(lcm(A, C), R);
    BigInt nBC1 = n(lcm(B, C), R);

    BigInt nABC1 = n(lcm(A, lcm(B, C)), R);

    BigInt nA2 = n(A, L - 1);
    BigInt nB2 = n(B, L - 1);
    BigInt nC2 = n(C, L - 1);

    BigInt nAB2 = n(lcm(A, B), L - 1);
    BigInt nAC2 = n(lcm(A, C), L - 1);
    BigInt nBC2 = n(lcm(B, C), L - 1);

    BigInt nABC2 = n(lcm(A, lcm(B, C)), L - 1);

    BigInt k("2"), q("3");
    BigInt res1 = nA1 + nB1 + nC1 - k*nAB1 - k*nAC1 - k*nBC1 + q*nABC1;
    BigInt res2 = nA2 + nB2 + nC2 - k*nAB2 - k*nAC2 - k*nBC2 + q*nABC2;
    
    BigInt res = res1;
    if (L > 0) res = res1 - res2;
    cout << res << "\n";

    return 0;
}

// res += A - n(lcm(a, b)) - n(lcm(a, c)) + n(lcm(a, b, c))
// res += 2 - 0 - 1 + 0 = 1
// res += B - n(lcm(b, a)) - n(lcm(b, c)) + n(lcm(a, b, c))
// res += 5 - 0 - 1 + 0 = 4
// res += C - n(lcm(c, a)) - n(lcm(c, b)) + n(lcm(a, b, c))
// res += 3 - 1 - 1 + 0 = 1
// 1 + 4 + 1 = 6
// lcm(10^19, 10^19-1) :v:v:v:v:v:v:v:v:v:v


// lcm dari 2 bilangan prima adalah a*b