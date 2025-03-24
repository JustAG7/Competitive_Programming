Đây chỉ là hướng dẫn tham khảo, tất nhiên các bạn có thể có solution khác và mình cũng khuyến khích các bạn nên tự làm hướng giải của các bạn trước khi đọc.
Xin cảm ơn

Giới thiệu Quy Hoạch động 1 chiều

??? "Help Conan!"
    - Tiến hành tính các giá trị A[i] theo như đề bài đã đưa ra
    - Lưu ý ở đây là đề bảo là lấy số lớn nhất từ A[1] -> A[n] với mỗi testcase
    - Sau khi tính a[i] xong thì ta lưu dp[i] = max(dp[i-1],A[i]) để đảm bảo nhận được số lớn nhất từ A[1] -> A[n]
    - `ĐPT: O(n)`


??? success "Code:"
    ```cpp
    dp[1] = res[1] = 1;
	ll ans = 1;
	for(int i=2;i<N;i++){
		if(i % 2 != 0) dp[i] = dp[i/2] + dp[i/2 + 1];
		else dp[i] = dp[i/2];
		ans = max(ans, dp[i]);
		res[i] = ans;
	}
    ```
??? "Fibo đầu tiên"
    - Tiến hành tính các giá trị f[i] theo như đề bài đã đưa ra
    - Lưu ý ở đây là có thể số rất lớn nên ta phải sử dụng `kiểu dữ liệu` cho phù hợp
    - `ĐPT: O(n)`


??? success "Code:"
    ```cpp
    int n;
	cin >> n;
	dp[1] = dp[2] = 1;
	if(n == 1) cout << "1";
	else cout << "1 1 ";
	for(int i=3;i<=n;i++){
		dp[i] = dp[i - 1] + dp[i - 2];
		cout << dp[i] << ' ';
	}
    ```

??? "CSES - Dice Combinations"
    - Ta có `dp[i] = số cách lớn nhất có thể tạo được tổng i`
    - Mỗi lần tung xúc sắc ta sẽ nhận được giá trị j và cộng kết quả vào dp[i] bằng cách lấy giá trị dp[i - j] để cộng
    - Ngoài lề: (có thể các bạn đã biết) nếu có biểu thức so sánh trong phép tính thì nếu biểu thức đó là true thì nó trả về 1, ngược lại 0
    - `ĐPT: O(6 * n) ~ O(n)`


??? success "Code:"
    ```cpp
    dp[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			(dp[i] += (i - j >= 0)*(dp[i - j])) %= M;
		}
	}
    ```

??? "Chú ếch và hòn đá 1"
    - Ta có mỗi `dp[i] = giá trị nhỏ nhất nếu ếch nhảy từ i - 1 hoặc i - 2`
    - Từ đó ta có thể lấy $dp[i] = min(dp[i - 2] + abs(a[i] - a[i - 2]), dp[i - 1] + abs(a[i] - a[i - 1]))$
    - Bởi vì dp[i - 2] và dp[i - 1] đã được tính toán tối ưu từ trước (cái này chắc các bạn biết rồi)
    - Lưu ý rằng với ô thứ 2 ta chỉ lấy vì con ếch đang đứng ở vị trí 1 dp[2] = abs(a[2] - a[1])
    - `ĐPT: O(n)`


??? success "Code:"
    ```cpp
    int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[2] = abs(a[2] - a[1]);
	for(int i=3;i<=n;i++){
		dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
	}
	cout << dp[n];
    ```

??? "CSES - Removing Digits"
    - Ta có mỗi `dp[i] = số lần thực hiện thao tác nhỏ nhất để i về 0`
    - Từ đó ta có thể lấy $dp[i] = min(dp[i], dp[i - num])$ với num là chữ số bất kì trong i
    - `ĐPT: O(10 * n)`


??? success "Code:"
    ```cpp
    int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[2] = abs(a[2] - a[1]);
	for(int i=3;i<=n;i++){
		dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
	}
	cout << dp[n];
    ```

??? "CSES - Chú ếch và hòn đá 2"
    - Bài này khác ở phần 1 là thay vì nhảy từ i đến i + 2 thì chú ếch giờ có thể nhảy từ i đến i + k
    - Ta vẫn lại có `dp[i] = giá trị nhỏ nhất nếu ếch nhảy từ i - 1 hoặc i - 2 hoặc i - k, vv...`
    - Từ đó ta có thể lấy $dp[i] = min(dp[i],dp[i - k] + abs(a[i] - a[k])$
    - Với `k từ i - k, i - k + 1, ..., i - 1`
    - `ĐPT: O(n * k)`


??? success "Code:"
    ```cpp
    int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> a[i];
	dp[1] = abs(a[1] - a[0]);
	for(int i=2;i<n;i++){
		ll temp = 1e18;
		for(int j=max(0,i - k);j<i;j++){
			temp = min(temp, dp[j] + abs(a[i] - a[j]));
		}
		dp[i] = temp;
	}
	cout << dp[n-1];
    ```

??? "CSES - Minimizing Coins"
    - Ta có `dp[i] = số xu nhỏ nhất tạo nên tổng i`
    - Từ đó ta có thể lấy $dp[i] = min(dp[i],dp[i - a[j]] + 1)$
    - `ĐPT: O(n * x)`


??? success "Code:"
    ```cpp
    int n,x;
	cin >> n >> x;
	memset(dp,M,sizeof(dp)); // M = 1e9 + 7
	dp[0] = 0;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=1;i<=x;i++){
		for(int j=0;j<n;j++){
			if(i - a[j] >= 0) dp[i] = min(dp[i],dp[i - a[j]] + 1);
		}
	}
	cout << (dp[x] >= N ? -1 : dp[x]); // N = 1e6 + 5
    ```

??? "CSES - Coin Combinations I"
    - Ta có `dp[i] = số cách để tạo nên tổng i`
    - Từ đó ta có thể lấy $dp[i] += dp[i - a[j]]$
    - `ĐPT: O(n * x)`


??? success "Code:"
    ```cpp
    int n,x;
	cin >> n >> x;
	for(int i=0;i<n;i++) cin >> a[i];
	dp[0] = 1; // ko lấy xu nào cũng là 1 cách
	for(int i=1;i<=x;i++){
		for(int j=0;j<n;j++){
			if(i - a[j] >=0) (dp[i] += (dp[i - a[j]])) %= M;
		}
	}
	cout << dp[x];
    ```

??? "Kì nghỉ của Kaninho"
    - Bởi vì Kaninho chỉ chọn được 1 trong 3 hoạt động nên ta tiến hành lấy độ hạnh phúc tối đa của 2 hoạt động của ngày i - 1 mà khác với hoạt động mà Kaninho sẽ làm tại ngày i
    - Từ đó ta có thể lấy 
    - $dp[i][1] = max(dp[i-1][2],dp[i-1][3]) + a$ với $a$ là độ hạnh phúc của hoạt động 1
    - $dp[i][2] = max(dp[i-1][1],dp[i-1][3]) + b$ với $b$ là độ hạnh phúc của hoạt động 2
    - $dp[i][3] = max(dp[i-1][1],dp[i-1][2]) + c$ với $c$ là độ hạnh phúc của hoạt động 3
    - Sau đó ta lấy max của $max(dp[n][1],max(dp[n][2],dp[n][3]))$ để lấy tối đa độ hạnh phúc
    - `ĐPT: O(n)`


??? success "Code:"
    ```cpp
    int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		dp[i][1] = max(dp[i-1][2],dp[i-1][3]) + a;
		dp[i][2] = max(dp[i-1][1],dp[i-1][3]) + b;
		dp[i][3] = max(dp[i-1][1],dp[i-1][2]) + c;
	}
	cout << max(dp[n][1],max(dp[n][2],dp[n][3]));
    ```

??? "Dãy con tăng dài nhất (bản dễ)"
    - Ta có `dp[i] = số lượng lớn nhất mà thỏa mãn điều kiện sao cho 1 <= j < i <= n`
    - Từ đó ta có thể lấy $dp[i] = max(dp[i],dp[j] + 1)$ `nếu a[i] > a[j]`
    - `ĐPT: O(n^2)`


??? success "Code:"
    ```cpp
    int n;
	cin >> n;
	for(int i=1;i<=n;i++) dp[i] = 1;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i] > a[j]) dp[i] = max(dp[i],dp[j] + 1);
		}
	}
	cout << *max_element(dp+1,dp+1+n);
    ```

??? "CSES - Coin Combinations II"
    - Bài này khác phần I là sau khi sắp xếp những xu tạo nên tổng i thì ta chỉ tính là 1 với tổng đó
    - Ví dụ $(2,3,3,3)$, $(3,2,3,3)$, $(3,3,3,2)$ cũng chỉ tính là 1 cách
    - Ta vẫn có `dp[i] = số cách để tạo nên tổng i`
    - Từ đó ta có thể lấy $dp[i] += dp[i - a[j]]$ 
    - Nhưng khác ở đây là thay vì chạy vòng lặp theo tổng xu thì ta sẽ chạy vòng lặp theo những đồng xu để đảm bảo tính chất của đề bài
    - `ĐPT: O(n*x)`


??? success "Code:"
    ```cpp
    int n,x;
	cin >> n >> x;
	for(int i=0;i<n;i++) cin >> a[i];
	dp[0] = 1;
	for(int i=0;i<n;i++){
		for(int j=1;j<=x;j++){
			if(j - a[i] >= 0) (dp[j] += (dp[j - a[i]])) %= M;
		}
	}
	cout << dp[x];
    ```

Đến đây là giới thiệu Quy Hoạch động 2 chiều

??? "Bandle City (DUTPC'21)"
    - Theo đề ta có chỉ được phép đi xuống hoặc sang phải
    - Vì vậy ta sẽ được $dp[i][j] = dp[i-1][j] + dp[i][j - 1]$
    - Hoặc có nghĩa là tại ô $(i,j)$ số cách sẽ là tổng cách đi từ ô $(i - 1, j)$ và ô $(i, j - 1)$ bởi vì theo như đề bài đã nói
    - `ĐPT: O(n*m)`


??? success "Code:"
    ```cpp
    int n,m;
	cin >> n >> m;
	char c;cin >> c;
	dp[1][1] = (c == '.'); // tại ô (1,1) chỉ có 1 cách duy nhất là đứng im tại đấy
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i == j && i == 1) continue;
			cin >> c;
			dp[i][j] = ((c == '.')*(dp[i][j-1] + dp[i-1][j]))%M;
		}
	}
	cout << dp[n][m];
    ```

??? "CSES - Array Description"
    - Bài này theo đánh giá của riêng mình thì đây là bài khó nhất trong contest này
    - Ta có `dp[i][j] = số cách để tạo nên dãy có độ dài là i nếu a[i] = j`
    - Ở đây ta sẽ có 2 trường hợp
    - Nếu $a[i] == 0$ ta có thể lấy bất cứ số nào (gọi là x) miễn là $x - 1 -> x + 1$ đó nằm trong khoảng $[1,m]$ 
    - Ngược lại ta sẽ lấy $a[i]-1 -> a[i] + 1$ sao cho nằm trong khoảng $[1,m]$
    - Lưu ý với số đầu tiên thì ta kiểm tra nếu $a[0] = 0$ thì lấy số nào cũng được, ngược lại thì chỉ tăng $dp[i][a[0]] = 1$
    - `ĐPT: O(n*m)`

??? success "Code:"
    ```cpp
    int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	if(a[0]) dp[0][a[0]] = 1;
	else fill(dp[0],dp[0] + 105,1);
	for(int i=1;i<n;i++){
		if(a[i]){
			dp[i][a[i]] += dp[i-1][a[i]];
			dp[i][a[i]] += (a[i] - 1 > 0)*(dp[i - 1][a[i] - 1]);
			dp[i][a[i]] += (a[i] + 1 <=m)*(dp[i - 1][a[i] + 1]);
			dp[i][a[i]] %= M;
		}
		else{
			for(int j=1;j<=m;j++){
				dp[i][j] += dp[i-1][j];
				dp[i][j] += (j - 1 > 0)*(dp[i - 1][j - 1]);
				dp[i][j] += (j + 1 <=m)*(dp[i - 1][j + 1]);
				dp[i][j] %= M;
			}
		}
	}
	ll ans = 0;
	for(int i=1;i<=m;i++){
		(ans += dp[n-1][i]) %= M; // ta chỉ lưu dp[n - 1][i] là số cách để lấy i tạo nên dãy n nên phải cộng dần
	}
	cout << ans;
    ```
??? "CSES - Edit Distance"
    - Thật ra bài này khá tương tự với bài Xâu con chung dài nhất
    - Ta có `dp[i][j] = số lần nhỏ nhất để biến a[0:i] thành b[0:j]`
    - Ta có 2 TH:
    - Nếu $a[i] == b[j]$ thì ta chỉ đổi $a[0:i-1]$ thành $b[0:j-1]$
    - Nếu $a[i] != b[j]$ thì ta vẫn đổi $a[0:i]$ thành $b[0:j]$ nhưng sẽ lấy số lượng nhỏ nhất đã được lưu trong mảng dp
    - `ĐPT: O(|a|*|b|)`


??? success "Code:"
    ```cpp
    string a,b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	memset(dp,M,sizeof(dp));
	dp[0][0] = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i == 0) dp[i][j] = j;
			else if(j == 0) dp[i][j] = i;
			else if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j - 1],min(dp[i - 1][j],dp[i][j - 1])) + 1;
		}
	}
	cout << dp[n][m];
	```

??? "Xâu con chung dài nhất"
    - Bài này nâng cao ở chỗ là phải in ra xâu chung dài nhất
    - Ta có `dp[i][j] = độ dài của xâu con chung dài nhất tính từ a[0:i] và b[0:j]`
    - Ta vẫn chia 2 TH:
    - Nếu $a[i] == b[j]$ thì ta coi như chỉ lấy độ dài ở $a[0:i-1]$ và $b[0:j-1]$ tăng lên 1
    - Ngược lại thì ta chỉ lấy độ dài của xâu con chung lớn nhất tính từ $a[0:i-1]$ và $b[0:j]$ hoặc $a[0:i]$ và $b[0:j-1]$
    - Để in ra xâu thì ta đi ngược lại để lấy xâu con, sử dụng 2 con trỏ để thao tác (ở đây là l và r)
    - Tức là nếu $a[i] == b[j]$ thì ta thêm vào đáp án xâu đó và trừ l và r đi 1
    - Ngược lại thì ta kiểm tra nếu độ dài xâu con chung dài nhất tính từ $a[0:i-1]$ và $b[0:j]$ hoặc $a[0:i]$ và $b[0:j-1]$
    - Nếu cái nào lớn hơn thì trừ đi tương ứng với l hoặc r
    - Sau đó đảo ngược lại xâu lại là ra đáp án
    - `ĐPT: O(|s|*|t|)`


??? success "Code:"
    ```cpp
    string a,b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string ans = "";
	int i = n, j = m;
	while(i>0 && j>0){
		if(a[i - 1] == b[j - 1]){
			ans += a[i - 1];
			i--;j--;
		}
		else{
			if(dp[i - 1][j] > dp[i][j - 1]) i--;
			else j--;
		}
	}
	reverse(all(ans));
	cout << ans;
	```

??? "Phép toán với ngăn xếp hai đầu"
    - Ta có `dp[l][r] = chênh lệch điểm số (Kaninho - Henry) nếu chỉ chơi mảng [l,r]`
    - Ở đây ta sẽ có 2 trường hợp
    - $l == r$ thì Kaninho là người lấy điểm ở $a[l]$ này
    - Ngược lại thì sẽ kiểm tra $max(a[l] - dp[l+1][r], a[r] - dp[l][r-1])$
    - Hay có nghĩa là lấy điểm đó trừ cái chênh lệch nếu tới lượt chơi của 1 trong 2 người 
    - `ĐPT: O(n^2)`

??? success "Code:"
    ```cpp
    int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int l=n - 1;l >= 0;l--){
		for(int r = l;r < n;r++){
			if(l == r) dp[l][r] = a[l];
			else dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
		}
	}
	cout << dp[0][n - 1];
    ```