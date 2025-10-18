# qr_generator.py
import qrcode

data = input("Enter the text or URL to generate QR code: ")
qr = qrcode.QRCode(
    version=1,
    box_size=10,
    border=5
)
qr.add_data(data)
qr.make(fit=True)

img = qr.make_image(fill_color="orange", back_color="white")
img.save("my_qr_code.png")

print("QR Code generated and saved as my_qr_code.png")
