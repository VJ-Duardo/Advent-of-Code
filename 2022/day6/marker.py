signal = ""
with open("signal.txt") as file:
    signal = file.read()

def get_start_marker_locaton(marker_size):
    for i in range(len(signal)-marker_size):
        if len(set(signal[i:i+marker_size])) == marker_size:
            return i+marker_size

print(get_start_marker_locaton(4))
print(get_start_marker_locaton(14))
