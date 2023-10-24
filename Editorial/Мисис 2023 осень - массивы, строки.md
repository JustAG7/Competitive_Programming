Đây chỉ là hướng dẫn tham khảo, tất nhiên các bạn có thể có solution khác và mình cũng khuyến khích các bạn nên tự làm hướng giải của các bạn trước khi đọc.
Xin cảm ơn

**Đứa nào coi cái này thì gà quá chời**

??? "A. Oath of the Night's Watch"
    - "Jon Snow likes to support a steward only if there exists at least one steward who has strength strictly less than him and at least one steward who has strength strictly greater than him"
    - Đây là câu thể hiện đề bài
    ??? "Dịch ý nghĩa của đề bài"
        - Jon chỉ giúp đỡ 1 steward nếu
        - Có ít nhất 1 steward có sức mạnh nhỏ hơn steward muốn giúp
        - Có ít nhất 1 steward có sức mạnh lớn hơn steward muốn giúp
    ??? "Hướng giải"
        - Chọn ra giá trị nhỏ nhất (gọi là $x$) và giá trị lớn nhất (gọi là $y$)
        - Đêm số lượng $a_i$ ($1 <= i <= n$) sao cho $x < a_i < y$
        - ĐPT: $O(n)$ hoặc $O(n*log(n))$ tùy vào cách bạn code

??? "B. Vlad and Cafes"
    - "In other words, he wants to find such a cafe that he hasn't been there for as long as possible"
    - Đây là câu thể hiện đề bài
    ??? "Dịch ý nghĩa của đề bài"
        Vlad muốn tìm quán cafe nào mà lần đầu đến là lâu nhất có thể
    ??? "Hướng giải"
        - Đếm có bao nhiêu giá trị khác nhau có trong mảng (gọi là $LIM$)
        - Lần lượt đi ngược từ $n$ -> $1$ nếu gặp số chưa đánh dấu thì đánh dấu số đó và tăng biến thăm lên (gọi là $cnt$)
        - Kiểm tra nếu $LIM == cnt$ thì in ngay số đó và dừng vòng lặp
        - ĐPT: $O(n)$ hoặc $O(n*log(n))$ tùy vào cách bạn code

??? "C. The Rank"
    - "Thomas's id is 1"
    - "In the table, the students will be sorted by decreasing the sum of their scores. So, a student with the largest sum will get the first place. If two or more students have the same sum, these students will be sorted by increasing their ids."
    - "Please help John find out the rank of his son."
    - Đây là những câu thể hiện đề bài
    ??? "Dịch ý nghĩa của đề bài"
        In ra thứ hạng của Thomas sau khi sắp xếp bảng điểm
    ??? "Hướng giải"
        - Lần lượt nhận vào theo cặp `(tổng điểm, id)` và sắp xếp giảm dần
        - Lưu ý cần phải tạo thêm hàm kiểm tra nếu số điểm bằng nhau thì id của ai thấp hơn thì người đó thứ hạng cao hơn
        - ĐPT: $O(n*(log(n))$


??? "D. Watering System"
    - Cả đề bài :v
    - **Lưu ý câu này:** "Arkady can only use the water that flows from the first hole."
    ??? "Dịch ý nghĩa của đề bài"
        - Số lỗ bít lại ít nhất sao cho có ít nhất B lít nước được chảy ra khỏi lỗ thứ nhất
        - Và không được bít lỗ thứ nhất
    ??? "Hướng giải"
        - Sắp xếp giảm dần từ $2$ -> $n$
        - Lấy sum là tổng của toàn bộ dãy $s$
        - Với $2 <= i <= n$ kiểm tra nếu thỏa mãn điều kiện của đề bài thì lập tức in $i$ và dừng vòng lặp
        - Điều kiện: $(s[1]*A) / S >= B$
        - ĐPT: $O(n*log(n))$

??? "E. YES or YES?"
    - **Có cái nịt tao mới hướng dẫn bài này**

??? "F. Mammoth's Genome Decoding"
    - "Your task is to decode the genome and replace each unrecognized nucleotide with one of the four types so that the number of nucleotides of each of the four types becomes equal."
    - Đây là những câu thể hiện đề bài
    ??? "Dịch ý nghĩa của đề bài"
        - Thay dấu `?` thành 1 trong 4 chữ `A,C,T,G` với điều kiện là số lượng mỗi chữ trong xâu phải bằng nhau
    ??? "Hướng giải"
        - Vì số lượng của mỗi chữ trong xâu phải bằng nhau nên điều kiện bắt buộc đầu tiên `n phải chia hết cho 4`, ngược lại in `===`
        - Ta gọi $amount$ chính là số lượng mỗi chữ cái phải có => $amount = n / 4$
        - Ta đếm tần suất từng chữ cái trong xâu $s$
        - Ta đi qua từng chữ cái (gọi là $freq$) nếu $freq > amount$ thì in `===`
        - Tùy cách bạn code để thay thế $s[i]$ thành 1 trong 4 chữ cái
        ??? "Cách thay"
            - Với mỗi tần suất ta push_back/append chữ cái đó vào vector/ []  với ($amount - freq$) lần
            - Sau đó chạy từng $s[i]$ nếu $s[i] == '?'$ thì thay lần lượt trong vector/ []
            - Xài 2 con trỏ hoặc pop_back() / pop(0)
        - ĐPT: $O(n)$ hoặc $O(n*log(n))$ tùy cách bạn code

??? "G. Pangram"
    - "A word or a sentence in some language is called a pangram if all the characters of the alphabet of this language appear in it at least once."
    - Đây là câu thể hiện đề bài
    ??? "Dịch ý nghĩa của đề bài"
        1 xâu được gọi là pangram nếu toàn bộ 26 chữ cái trong bảng chữ cái có trong xâu
    ??? "Hướng giải"
        - Đánh dấu từng chữ cái xuất hiện trong xâu $s$
        - Nếu tất cả cùng xuất hiện thì in `YES`, ngược lại ít nhất 1 chữ cái không có trong xâu $s$ thì in `NO`
        - ĐPT: $O(n*26)$

??? "H. Hotelier"
    - 2 đoạn đầu của đề (không phải 2 câu đầu) :v
    ??? "Dịch ý nghĩa của đề bài"
        - Nếu khách chọn `L` thì sẽ chọn căn phòng trống gần nhất từ trái sang
        - Nếu khách chọn `R` thì sẽ chọn căn phòng trống gần nhất từ phải sang
        - Nếu khách chọn `số` là khách trả phòng
    ??? "Hướng giải"
        - Sử dụng cấu trúc dữ liệu set<int> gọi là $S$ https://www.geeksforgeeks.org/set-in-cpp-stl/
        ??? "Cách làm"
            - Ta thêm từ $0$ đến $9$ vào trong $S$
            - Lần lượt đi từng $s[i]$ nếu
            - $s[i] == 'L'$ thì lấy số đầu tiên có trong $S$ và loại ra khỏi $S$
            - $s[i] == 'R'$ thì lấy số cuối cùng có trong $S$ và loại ra khỏi $S$
            - $s[i] == number$ thì lấy number bỏ vào lại trong $S$
            - ĐPT: $O(n*log(n))$