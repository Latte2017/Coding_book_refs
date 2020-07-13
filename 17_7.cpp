/*
Given a number print english phrase

111 is one hundred and elven
*/
#include<string>
#include<map>
#include<vector>
using namespace std;

class NumberToEnglish {
private:
	
	//Can one use vector because we need the indexing. Donot use map
	vector<string> tens = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	vector<string> ones = { "", "", "Two", "Three", "Four", "Five", "Six",  "Seven", "Eight", "Nine", "Ten", "Eleven",
		"Twelve", "Thirteen", "Forteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	
public:
	string num2eng(int num) {
		int q = 0;
		string ret_str = "";
		while (num > 0) {
			if (num > (pow(10,9))) {
				q = num / (pow(10,9));
				num = num % int(pow(10,9));
				ret_str += num2eng(q) + " Billion " ;
			}
			else if (num > (pow(10,6))) {
				q = num / (pow(10,6));
				num = num % int(pow(10,6));
				ret_str += num2eng(q) + " Million ";
			}
			else if (num > (pow(10,3))) {
				q = num / (pow(10,3));
				num = num % int(pow(10,3));
				ret_str += num2eng(q) + " Thousand ";
			}
			else if (num > (pow(10,2))) {
				q = num / (pow(10,2));
				num = num % int(pow(10,2));
				ret_str += num2eng(q) + " Hundred ";
			}
			else if (num > 19 and num <= 99) {
				for (auto it = tens.size() - 1; it != -1; --it) {
					if ((num / (it * 10)) > 0) {
						q = num / (it * 10);
						num = num % (it * 10);
						ret_str += tens[it] + " ";
						break;
					}
				}
			}
			else if (num <= 19 and num > 1) {
				for (auto it = ones.size() - 1; it != -1; --it) {
					if ((num / (it)) > 0) {
						q = num / (it);
						num = num % (it);
						ret_str += ones[it] + " ";
						break;
					}
				}
			}

			else {
				ret_str += "One ";
				num -= 1;
			}

		}
		if (!ret_str.empty()) {
			ret_str.pop_back();
		}
		return ret_str;
	}
};

int main() {
	int num = 1981;
	NumberToEnglish n1;
	string ret_str = n1.num2eng(num);
}