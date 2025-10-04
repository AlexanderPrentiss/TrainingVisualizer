import ctypes
import os

lib = ctypes.CDLL(os.path.abspath("./build/libTrainVis.so"))
# Set argument and return types
lib.init_vis.restype = ctypes.c_void_p
lib.start_vis.argtypes = [ctypes.c_void_p]

# Initialize the visualization object
vis_obj = lib.init_vis()

# Start the OpenGL window
lib.start_vis(vis_obj)
