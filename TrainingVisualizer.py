import ctypes
import os

lib = ctypes.CDLL(os.path.abspath("./build/libTrainVis.dylib"))
lib.init_vis.restype = ctypes.c_void_p
lib.start_vis.argtypes = [ctypes.c_void_p]
lib.vis_exit.argtypes = [ctypes.c_void_p]
lib.vis_should_window_close.argtypes = [ctypes.c_void_p]

class Visualizer():
	def __init__(self):
		self.vis_obj = lib.init_vis() # Initialize vis

	def run_window(self):
		try:
			while not lib.vis_should_window_close(self.vis_obj):
				lib.start_vis(self.vis_obj)
		except KeyboardInterrupt:
			print("Keyboard Interrupt, Exiting...")
		finally:			
			lib.vis_exit(self.vis_obj)

