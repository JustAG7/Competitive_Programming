Về phần code 
	- Code web (HTML/ CSS/ React): được phép sử dụng các thư viện trên mạng, code ra được 1 trong 2 đề sau
		- (1) trang giới thiệu bản thân (bao gồm họ tên, sở thích, lớp, trường, tiểu sử bản thân,...) 
		- (2) Trang đăng nhập tài khoản bao gồm: tài khoản, mật khẩu, captcha chữ, ô remember me, nút đăng nhập, nút đăng nhập qua gmail, facebook,
		nút dẫn qua link đăng ký tài khoản (chỉ cần hiện ra đẹp không nhất thiết phải chạy được) 
		- Nếu làm (1) thì yêu cầu tính thẩm mỹ cao, nếu làm (2) thì yêu cầu tính đơn giản, đủ đẹp mắt
	- Code sản phẩm (Java/ Python): 
		- (1) Tạo nên một cái đồng hồ chạy thời gian thực, hiển thị theo AM,PM (sử dụng Thread)
		- (2) Tạo nên một app lấy mật khẩu mới chỉ bao gồm phần nhập mail, sử dụng mail bất kì để gửi mật khẩu mới vào cái mail đã nhập trong ô		
	- Code thuật toán (C++/Python): contest riêng
		- 2 câu cài đặt: dễ
		- 1 câu toán: dễ
		- 1 câu tham: dễ
		- 1 câu đồ thị: trung bình (câu tgian làm bài)
		- 1 câu sắp xếp + tham lam: dễ (câu tgian làm bài)
Về phần quản lý dữ liệu
	- Đề: HoT đang tiến hành làm đợt trại, các ban sau đây đều có các nhiệm vụ:
		- Ban Photo: chụp ảnh, quay phim
		- Ban Nhân sự/ Hậu cần: chạy sự kiện, cần biết ai đang chạy/ đã về
		- Ban Design + Content: làm bài đăng
	Các bạn cần phải đảm bảo kê khai tài sản cá nhân, cũng như sạc pin đầy đủ mới có thể chạy sự kiện một cách chỉn chu. 
	- Yêu cầu: Hãy vẽ ra 1 cái cấu trúc nhánh để lưu trữ tất cả dữ liệu trên
	- VD về cấu trúc nhánh để thể hiện cơ bản hệ thống HoT
		|-----Người
		|		|
		|		|
		|		|----- Tên
		|		|
		|		|----- Tuổi
		|		|
		|		|----- ....
		|
		|
		|-----HoT
		|		|
		|		|----- Ban Design
		|		|
		|		|----- Ban Content
		|		|
		|		|----- ...
		|
		|
		|-----...