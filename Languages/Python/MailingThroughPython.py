import smtplib
import numpy as np
import argparse
parser = argparse.ArgumentParser()
parser.add_argument('Mail',
                       metavar='mailid',
                       type=str,
                       help='the mail id you want to use while sending mail.')
parser.add_argument('password',
                       metavar='pass',
                       type=str,
                       help='the password of the id you want to use while sending mail.')
parser.add_argument('Pathcontent',
                       metavar='pathcontent',
                       type=str,
                       help='the path of content file')
parser.add_argument('csvfile',
                       metavar='CSVfile',
                       type=str,
                       help='the path of csv file')
# Execute the parse_args() method
args = parser.parse_args()
your_mail = args.Mail
pass_word = args.password
content = open(args.Pathcontent,"r").read()
workshop = np.genfromtxt(args.csvfile,delimiter=",",dtype = object)
server    = smtplib.SMTP_SSL('smtp.gmail.com', 465)
server.login(your_mail,pass_word )
for name, mail in workshop:
    server.sendmail(
      your_mail, 
      mail.decode("utf-8"), 
      content.format(name.decode("utf-8")))
server.quit()
