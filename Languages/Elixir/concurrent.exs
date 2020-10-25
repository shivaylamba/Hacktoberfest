defmodule Concurrent do
  def run(tasks \\ 10, milliseconds \\ 10000, timeout \\ 20000) do
    opts = [max_concurrency: System.schedulers_online, timeout: timeout]
    for task <- 1..tasks do
      task
    end
    |> Task.async_stream(fn task ->
      Process.sleep(milliseconds)
      task * 2
    end, opts)
    |> Enum.to_list()
  end
end
