```bash
                                ___                                                                                
                               (   )                                                                               
   .-..     .--.    ___ .-.     | |_         .--.      .--.      .---.   ___ .-.    ___ .-.     .--.    ___ .-.    
  /    \   /    \  (   )   \   (   __)     /  _  \    /    \    / .-, \ (   )   \  (   )   \   /    \  (   )   \   
 ' .-,  ; |  .-. ;  | ' .-. ;   | |       . .' `. ;  |  .-. ;  (__) ; |  |  .-. .   |  .-. .  |  .-. ;  | ' .-. ;  
 | |  . | | |  | |  |  / (___)  | | ___   | '   | |  |  |(___)   .'`  |  | |  | |   | |  | |  |  | | |  |  / (___) 
 | |  | | | |  | |  | |         | |(   )  _\_`.(___) |  |       / .'| |  | |  | |   | |  | |  |  |/  |  | |        
 | |  | | | |  | |  | |         | | | |  (   ). '.   |  | ___  | /  | |  | |  | |   | |  | |  |  ' _.'  | |        
 | |  ' | | '  | |  | |         | ' | |   | |  `\ |  |  '(   ) ; |  ; |  | |  | |   | |  | |  |  .'.-.  | |        
 | `-'  ' '  `-' /  | |         ' `-' ;   ; '._,' '  '  `-' |  ' `-'  |  | |  | |   | |  | |  '  `-' /  | |        
 | \__.'   `.__.'  (___)         `.__.     '.___.'    `.__,'   `.__.'_. (___)(___) (___)(___)  `.__.'  (___)       
 | |                                                                                                               
(___)
```

A simple TCP port scanner written in C. Given a hostname or IP and a port range,
it attempts a TCP connection on each port and prints the one that are open,
along with the know service name.

## Usage

### Compile

```bash
gcc portscanner.c -o portscanner
```

### Run

```bash
./portscanner
```

You will be prompted for:
- Hostname or IP address (e.g. `192.168.1.1` or `example.com`)
- Start port
- End port

## How it works

- Accepts both IP addresses and hostnames (resolved via `gethostbyname`)
- Opens a raw TCP socket per port and attempts `connect()`
- Uses `getservbyport()` to map port numbers to known service names (ssh, http, etc.)
- Only open ports are printed

## Requirements

- Linux or macOS
- GCC or Clang

## Limitations

- TCP only, no UDP
- No timeout configured — slow on large port ranges
- Single-threaded, ports are scanned sequentially
- No CIDR / multiple host support

## Legal

Only scan hosts you own or have explicit permission to scan.
Unauthorized port scanning may be illegal in your jurisdiction.
