def kiem_tra_ngoac(bieu_thuc):
  """
  Kiểm tra xem các dấu ngoặc trong biểu thức có được mở và đóng đúng cách hay không.

  Tham số:
    bieu_thuc: Chuỗi biểu thức toán học cần kiểm tra.

  Trả về:
    True nếu biểu thức có dấu ngoặc hợp lệ, False nếu ngược lại.
  """
  ngan_xep = []
  cap_ngoac = {')': '(', '}': '{', ']': '['}

  for ky_tu in bieu_thuc:
    if ky_tu in cap_ngoac.values():  # Nếu là dấu mở ngoặc
      ngan_xep.append(ky_tu)
    elif ky_tu in cap_ngoac:  # Nếu là dấu đóng ngoặc
      if not ngan_xep:
        return False  # Ngăn xếp rỗng mà gặp dấu đóng ngoặc
      dinh_ngan_xep = ngan_xep.pop()
      if cap_ngoac[ky_tu] != dinh_ngan_xep:
        return False  # Dấu đóng ngoặc không khớp với dấu mở ngoặc

  return not ngan_xep  # Nếu ngăn xếp rỗng sau khi duyệt hết thì hợp lệ


# Ví dụ
bieu_thuc_hop_le_1 = "{[()]}"
bieu_thuc_hop_le_2 = "()[]{}"
bieu_thuc_khong_hop_le_1 = "{[(])}"
bieu_thuc_khong_hop_le_2 = "{[()"
bieu_thuc_khong_hop_le_3 = "}}"


print(f"'{bieu_thuc_hop_le_1}' hợp lệ: {kiem_tra_ngoac(bieu_thuc_hop_le_1)}")  # True
print(f"'{bieu_thuc_hop_le_2}' hợp lệ: {kiem_tra_ngoac(bieu_thuc_hop_le_2)}")  # True
print(f"'{bieu_thuc_khong_hop_le_1}' hợp lệ: {kiem_tra_ngoac(bieu_thuc_khong_hop_le_1)}")  # False
print(f"'{bieu_thuc_khong_hop_le_2}' hợp lệ: {kiem_tra_ngoac(bieu_thuc_khong_hop_le_2)}")  # False
print(f"'{bieu_thuc_khong_hop_le_3}' hợp lệ: {kiem_tra_ngoac(bieu_thuc_khong_hop_le_3)}")  # False