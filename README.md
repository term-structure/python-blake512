# blake512

blake512 is a Python implementation for the BLAKE-1 512 bits hashing algorithm

Special thank to the SPHINCS project for the C implementation.

## Installation

To install, clone the repository and run :
```bash
python3 setup.py install
```

You might need to use `sudo`.

## Usage

```python
import blake512

blake512.hash('')
# 'a8cfbbd73726062df0c6864dda65defe58ef0cc52a5625090fa17601e1eecd1b628e94f396ae402a00acc9eab77b4d4c2e852aaaa25a636d80af3fc7913ef5b8'
blake512.hash('The quick brown fox jumps over the lazy dog')
# '1f7e26f63b6ad25a0896fd978fd050a1766391d2fd0471a77afb975e5034b7ad2d9ccf8dfb47abbbe656e1b82fbc634ba42ce186e8dc5e1ce09a885d41f43451'
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[GPLv3](https://www.gnu.org/licenses/gpl-3.0.html)
