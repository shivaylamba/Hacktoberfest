from queue import Queue

class PrintSpooler:
    def __init__(self):
        self.print_queue = Queue()

    def add_print_job(self, job):
        self.print_queue.put(job)
        print("Added print job:", job)

    def print_next_job(self):
        if not self.print_queue.empty():
            job = self.print_queue.get()
            print("Printing:", job)
        else:
            print("Print queue is empty.")

if __name__ == "__main__":
    spooler = PrintSpooler()
    spooler.add_print_job("Document1.pdf")
    spooler.add_print_job("Image.jpg")
    spooler.add_print_job("Spreadsheet.xlsx")

    print("Printing jobs:")
    spooler.print_next_job()
    spooler.print_next_job()
    spooler.print_next_job()
    spooler.print_next_job()
