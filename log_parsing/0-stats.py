#!/usr/bin/python3
"""
Log parsing
"""
import sys
import signal


def print_stats(total_size, status_codes):
    """Prints the statistics"""
    print("File size: {:d}".format(total_size))
    for key in sorted(status_codes.keys()):
        print("{:d}: {:d}".format(key, status_codes[key]))


def signal_handler(sig, frame):
    """Handles the SIGINT signal"""
    print()
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)

total_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0}
counter = 0

try:
    for line in sys.stdin:
        counter += 1
        try:
            words = line.split()
            total_size += int(words[-1])
            status_codes[int(words[-2])] += 1
        except Exception:
            pass
        if counter == 10:
            print_stats(total_size, status_codes)
            counter = 0
except KeyboardInterrupt:
    print_stats(total_size, status_codes)
    raise

print_stats(total_size, status_codes)
