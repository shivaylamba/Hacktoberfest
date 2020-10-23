from PyPDF2 import PdfFileReader, PdfFileWriter
write_obj=PdfFileWriter()
pdf_list=["PATH OF PDF1","PATH TO PDF2"]

for i in pdf_list:
	read_obj=PdfFileReader(i)
	pages=read_obj.getNumPages()
	for j in range(pages):
		p=read_obj.getPage(j)
		write_obj.addPage(p)

write_obj.encrypt("PASSWORD", "PASSWORD2", True)
pdf_file=open("PATH OF MERGED PDF",'wb')
write_obj.write(pdf_file)
