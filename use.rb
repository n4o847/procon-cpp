# usage:
#   ./use FOO BAR

clip = IO.popen("clip", "w")
ARGV.uniq.compact.each do |name|
  file = File.read("./lib/#{name}.cpp")
  clip.puts file[/(?<=\/\/ BEGIN).*(?=\/\/ END)/m].strip.gsub(/\n\s*/, " ")
end
clip.close
puts "done"
