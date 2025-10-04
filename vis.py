import ctypes
import os

lib = ctypes.CDLL(os.path.abspath("./build/libTrainVis.so"))
# Set argument and return types
lib.init_vis.restype = ctypes.c_void_p
lib.start_vis.argtypes = [ctypes.c_void_p]
lib.vis_exit.argtypes = [ctypes.c_void_p]
lib.vis_should_window_close.argtypes = [ctypes.c_void_p]

if __name__ == '__main__':
    # Initialize the visualization object
    vis_obj = lib.init_vis()

    # Start the OpenGL window
    try:
        while not lib.vis_should_window_close(vis_obj):
            lib.start_vis(vis_obj)
    except KeyboardInterrupt:
        print("Exiting...")
    finally:
        lib.vis_exit(vis_obj)
