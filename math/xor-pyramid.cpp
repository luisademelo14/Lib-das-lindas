/*
Problem: Consider a xor pyramid where each number is the xor of lower-left and lower-right numbers. Given the bottom row of the pyramid, your task is to find the topmost number.
Solution: Lucas theorem 
 */

int n, resp, arr[MAX];
 
int main()
{_
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i];
		if (((n-1)&i) == i) resp ^= arr[i];
	}
 
	cout << resp << endl;
}
