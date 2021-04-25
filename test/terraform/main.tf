locals {
  name = "value"
}

output name {
  value       = local.value
  description = "example basic terraform"
}

