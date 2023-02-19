### For <300-0-5, 300-0-4000, 4100-0-5, 4100-0-4000>.txt files

```cs
using System;
using System.IO;

Random random = new Random();
var result = "";
result += 4100 + " "; // or 300
for (int i = 0; i < 4100; i++) // or i < 300
{
     result += random.Next(0, 5) + " ";
     // or random Next(0, 4000)
}
File.WriteAllText("<file-name>.txt", result);
```

### For <300-almost-sorted, 4100-almost-sorted>.txt

```cs
using System;
using System.IO;

Random random = new Random();
var result = "";
var start = 111;
result += 4100 + " "; // or 300
for (var i = 0; i < 4100; i++) // or i < 300
{
     start += random.Next(-20, 100);
     result += start + " ";
}
File.WriteAllText("<file-name>.txt", result);
```

### For 300-reversed.txt

```cs
using System;
using System.IO;

Random random = new Random();
var result = "";
SortedSet<int> numbers = new SortedSet<int>();
result += 300 + " ";
for (var i = 0; i < 300; i++)
{
     var r = random.Next(1, 4100);
     while (numbers.Contains(r))
     {
          r = random.Next(1, 4100);
     }
     numbers.Add(r);
}
File.WriteAllText("300-reversed.txt", result);
```

### For 4100-reversed.txt

```cs
using System;
using System.IO;

Random random = new Random();
var result = "";
result += 4100 + " ";
for (var i = 4100; i >= 1; i--)
{
     result += i + " ";
}
File.WriteAllText("4100-reversed.txt", result);
```