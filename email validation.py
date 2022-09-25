# Email name should be starts with alphabet and should follow by numbers or underscore.
# It should contains either numbers or underscore finally ends with @gmail.com only then given email id is true Otherwise False
mail = input("Enter Mail : ")
count = 0
for i in range(len(mail)):
    if i == 0:
        if mail[i] >= 'a' and mail[i] <= 'z':
            continue
        else:
            print("false")
            break
    elif mail[i] >= 'a' and mail[i] <= 'z':
        continue
    else:
        if (mail[i] >= '0' and mail[i] <= '9') or mail[i] == '_':
            if count == 0:
                count += 1
            else:
                print("false")
                break
        elif mail[i] == '@' and count == 1:
            if mail[i:(i+10)] != "@gmail.com":
                print("false")
                break
            else:
                print("True")
                break
        else:
            print("false")
            break
