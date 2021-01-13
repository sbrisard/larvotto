import configparser
import os.path

import pybind11
import setuptools


def get_metadata(key):
    with open(os.path.join("..", "metadata", key+".txt"), "r", encoding="utf8") as f:
        return f.read().strip()


if __name__ == "__main__":
    metadata = {
        "name": "larvotto",
        "version": get_metadata("version"),
        "author": get_metadata("author"),
        "author_email": "email",
        "description": get_metadata("description"),
        "url": get_metadata("repository"),
    }

    with open(os.path.join("..", "README.md"), "r") as f:
        metadata["long_description"] = f.read()

    config = configparser.ConfigParser()
    config.read("setup.cfg")
    larvotto_include_dir = config["larvotto"].get("include_dir", "")
    larvotto_library_dir = config["larvotto"].get("library_dir", "")

    larvotto = setuptools.Extension(
        "larvotto.larvotto",
        include_dirs=[pybind11.get_include(),
                      larvotto_include_dir],
        sources=[os.path.join("larvotto",
                              "larvotto.cpp")],
        libraries=["larvotto"],
        library_dirs=[larvotto_library_dir],
    )

    setuptools.setup(
        long_description_content_type="text/markdown",
        packages=setuptools.find_packages(),
        ext_modules=[larvotto],
        **metadata
    )
