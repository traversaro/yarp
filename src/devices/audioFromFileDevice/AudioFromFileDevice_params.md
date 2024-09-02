* |   |  use_params_from_file | bool    | -              |  true                    | No                          | If set to true, recording params (e.g. channels, freq etc. are taken from file. Otherwise are AUDIO_BASE parameters are used and the file is converted to the specified format |       |
* |   |  file_name            | string  | -              |  audio.wav               | No                          | The name of the file opened by the module                         | Only .wav files supported   |
* |   |  period               | double  | s              |  0.010                   | No                          | the period of thread which processes the file                     | On each iteration xxx samples are processed |
* |   |  driver_frame_size    | int     | samples        |  512                     | No                          | the number of samples to process on each iteration of the thread  | - |
* |   |  reset_on_stop        | bool    | -              |  false                   | No                          | if enabled, the file is played back from the beginning every stop. Otherwise on start the previous position is resumed | - |