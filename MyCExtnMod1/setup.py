import os
import sys


from distutils.core import setup, Extension


module1 = Extension('MyCExtnMod1',
                    sources = ['MyCExtnSrc1.c'])

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a MyCExtnMod1 package',
       ext_modules = [module1])
