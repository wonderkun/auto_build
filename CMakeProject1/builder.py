import base64
import binascii
import subprocess
import pbkdf2
from Crypto.Cipher import AES
import re
import os

def aes_pad(data: bytes) -> bytes:
    """
    Pad the data to make sure we are %16 == 0
    """
    bs = AES.block_size
    while len(data) % bs != 0:
        data += b"\x90"

    return data


def get_crypto_data(password: str) -> tuple:
    """
    Uses pbkdf2 to build a KEY and IV pair.
    """
    salt = os.urandom(16)
    key = pbkdf2.PBKDF2(password, salt).read(32)
    iv = pbkdf2.PBKDF2(password, salt).read(48)[32:]
    return (key, iv, salt)


def build_c_vars(data: bytes) -> str:
    """
    Takes in any string, separates for each 2 chars, assumes they're
    bytes and puts it into proper C syntax for byte array.
    """
    data = binascii.hexlify(data).decode("utf-8")
    split_data = re.findall("..", data)
    c_data = ""
    for i, b in enumerate(split_data):
        if i == (len(split_data) - 1):
            c_data += f"0x{b}"
        else:
            c_data += f"0x{b},"
    return c_data

def aes_encrypt(data: bytes, key: bytes, iv: bytes) -> str:
    """
    Takes in data to encrypt, a key, and an iv. Encrypts the
    data with AES256, encodes the encrypted bytes with base64.
    """
    cipher = AES.new(key, AES.MODE_CBC, IV=iv)
    encrypted_data = cipher.encrypt(data)
    return base64.b64encode(encrypted_data)

if __name__ == "__main__":
    fd = open("./zhudong","rb")
    data = fd.read()
    enc_pass = "D78xNiihULLe9wuU"
    key, iv, salt = get_crypto_data(enc_pass)
    raw_padded_shellcode = aes_pad(data)
    encrypted_encoded_shellcode = aes_encrypt(raw_padded_shellcode, key, iv)
    c_key = "uint8_t key[32] = {%s};" % build_c_vars(key)
    c_iv = "uint8_t iv[16] = {%s};" % build_c_vars(iv)
    c_shellcode = "uint8_t ENC_STR[] = {%s};" % build_c_vars(encrypted_encoded_shellcode)
    # build_c_vars()
    print(c_key)
    print(c_iv)