server=smtplib.SMTP("smtp.gmail.com",587)
server.starttls()
a=input("enter mail")
b=input("enter password")
server.login('%s'%a,'%s'%b)

server.sendmail('from_mail@gmail.com',
                'to_mail@gmail.com',
                "message")

server.quit()

print("email sent successfully")
