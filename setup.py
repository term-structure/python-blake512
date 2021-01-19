from distutils.core import setup, Extension

def main():
    setup(name="blake512",
          version="1.0.0",
          description="Python interface for the blake512 hashing function",
          author="tweqx",
          ext_modules=[Extension("blake512", ["src/blake.c", "blake512.c"])])

if __name__ == "__main__":
    main()
