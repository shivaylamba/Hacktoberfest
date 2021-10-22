import hashlib

def dictionary_attack(password_hash):

    dictionary = ['letmein','password','12345','football']

    password_found = False

    for dictionary_value in dictionary:
        hashed_value = (hashlib.md5(dictionary_value.encode('utf-8'))).hexdigest()
        if hashed_value == password_hash:
            password_found = True
            recovered_password = dictionary_value

    if password_found == True:
        print ('Found match for hashed value \n',password_hash)
        print ('Password recovered: ',recovered_password)
    else:
        print ('password was not found')


def hashing_method(passwd_hash):
    hash1 = hashlib.md5(passwd_hash.encode('utf-8'))
    return hash1.hexdigest()

def main():
    print ('Password hashing script')
    passwd_hash = input ('Enter your password: ')
    hash2 = hashing_method(passwd_hash)
    dictionary_attack(hash2)

if __name__ == '__main__':
        main()












