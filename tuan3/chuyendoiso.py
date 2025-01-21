def thap_phan_sang_nhi_phan(so_thap_phan):
  """
  Chuyển đổi một số từ hệ thập phân sang hệ nhị phân sử dụng ngăn xếp.

  Tham số:
    so_thap_phan: Số thập phân cần chuyển đổi.

  Trả về:
    Chuỗi biểu diễn số nhị phân tương ứng.
  """
  ngan_xep = []

  while so_thap_phan > 0:
    phan_du = so_thap_phan % 2
    ngan_xep.append(phan_du)
    so_thap_phan //= 2

  so_nhi_phan = ""
  while ngan_xep:
    so_nhi_phan += str(ngan_xep.pop())

  return so_nhi_phan if so_nhi_phan else "0" # Xử lý trường hợp số thập phân là 0

# Ví dụ
so_thap_phan = 13
so_nhi_phan = thap_phan_sang_nhi_phan(so_thap_phan)
print(f"Số thập phân: {so_thap_phan}")
print(f"Số nhị phân: {so_nhi_phan}")

so_thap_phan = 0
so_nhi_phan = thap_phan_sang_nhi_phan(so_thap_phan)
print(f"Số thập phân: {so_thap_phan}")
print(f"Số nhị phân: {so_nhi_phan}")

so_thap_phan = 25
so_nhi_phan = thap_phan_sang_nhi_phan(so_thap_phan)
print(f"Số thập phân: {so_thap_phan}")
print(f"Số nhị phân: {so_nhi_phan}")